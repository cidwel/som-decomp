.setcpu "65816"
.segment "CODE"
.org $F4EA
map_control_0df4ea:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
