.setcpu "65816"
.segment "CODE"
.org $99C9
map_control_0f99c9:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
