.setcpu "65816"
.segment "CODE"
.org $F5DB
map_control_0df5db:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
