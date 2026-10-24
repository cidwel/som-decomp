; Numeric AB88/AAFF ten-byte descriptor; C7B480 decoded resource.
.setcpu "65816"
.segment "RODATA"
.org $601E
entry_601e = $7EB949
repeat_601e = $7EB96B
warm_task_descriptor_601e:
    .faraddr entry_601e
    .byte $70 ; priority: AAFF local07 -> task03
    .word .loword(repeat_601e) ; AA42 repeated task near target
    .word $0100 ; copied word6; not an allocation count
    .word $0000 ; AAFF local0C -> optional B0A1 size
