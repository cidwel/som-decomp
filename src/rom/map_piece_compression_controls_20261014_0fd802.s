.setcpu "65816"
.segment "CODE"
.org $D802
map_control_0fd802:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
