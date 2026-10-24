; Numeric AB88/AAFF ten-byte descriptor; C7B480 decoded resource.
.setcpu "65816"
.segment "RODATA"
.org $6014
entry_6014 = $7EB312
repeat_6014 = $7EB333
warm_task_descriptor_6014:
    .faraddr entry_6014
    .byte $80 ; priority: AAFF local07 -> task03
    .word .loword(repeat_6014) ; AA42 repeated task near target
    .word $0100 ; copied word6; not an allocation count
    .word $0000 ; AAFF local0C -> optional B0A1 size
