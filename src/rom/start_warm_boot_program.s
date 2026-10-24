; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_hardware_and_load_boot_program = $4D0F

.segment "CODE"
.org $4CFA
start_warm_boot_program:
    rep #$10
    rep #$20
    .a16
    lda #$01FF
    tcs
    sep #$20
    .a8
    lda #$00
    pha
    plb
    jsr initialize_hardware_and_load_boot_program
    jml f:$7EAF28
