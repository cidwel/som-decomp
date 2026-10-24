; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A

.segment "CODE"
.org $5990
enqueue_physical_critical_hit_notice:
    jsr allocate_reverse_combat_message_slot
    jsr append_actor_name_message_token
    .i16
    ldx #$62B7
    jsr append_rom_message_text
    rtl
