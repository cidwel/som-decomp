; Numeric ten-byte particle descriptor selected at 7ED067; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $5F1C
entry_particle = $7E98AF
repeat_particle = $7E990D
cold_particle_task_descriptor:
    .faraddr entry_particle
    .byte $80 ; AAFF task priority
    .word .loword(repeat_particle) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
