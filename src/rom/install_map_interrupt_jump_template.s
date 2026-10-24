; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


map_interrupt_jump_template = $BC93
map_interrupt_ram_slots = $0100

.segment "CODE"
.org $BC85
install_map_interrupt_jump_template:
    sep #$30
    .i8
    ldx #$07
install_map_interrupt_jump_template_c0bc89:
    lda a:map_interrupt_jump_template,X
    sta a:map_interrupt_ram_slots,X
    dex
    bpl install_map_interrupt_jump_template_c0bc89
    rts
