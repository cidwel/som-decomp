; Numeric AB88/AAFF ten-byte descriptor; C7B480 decoded resource.
.setcpu "65816"
.segment "RODATA"
.org $60BE
entry_60be = $7ECA41
repeat_60be = $7ECA56
warm_task_descriptor_60be:
    .faraddr entry_60be
    .byte $80 ; priority: AAFF local07 -> task03
    .word .loword(repeat_60be) ; AA42 repeated task near target
    .word $0100 ; copied word6; not an allocation count
    .word $0000 ; AAFF local0C -> optional B0A1 size
