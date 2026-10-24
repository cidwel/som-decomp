.setcpu "65816"
.segment "CODE"
.org $28AE
map_control_0d28ae:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
