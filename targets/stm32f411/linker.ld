ENTRY(Reset_Handler)

MEMORY
{
    FLASH   (rx)    :   ORIGIN = 0x08000000, LENGTH = 512K
    RAM     (rw)    :   ORIGIN = 0x20000000, LENGTH = 128K
}  

SECTIONS
{
    .text   :
    {
        *(.vector_table)
        *(.text)
            _startofdatalma = .;
    } >FLASH

    .data   :
    {
    _startofdatavma = .;
    *(.rodata)
    *(.data)
    _endofdatavma = .;

    } >RAM AT >FLASH

.bss    :
{
    _startofbssvma = .;
        *(.bss)
        _endofbssvma = .;
    } >RAM

}
