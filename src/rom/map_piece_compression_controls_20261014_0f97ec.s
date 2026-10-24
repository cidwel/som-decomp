.setcpu "65816"
.segment "CODE"
.org $97EC
map_control_0f97ec:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
