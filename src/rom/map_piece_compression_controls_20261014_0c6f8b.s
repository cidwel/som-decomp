.setcpu "65816"
.segment "CODE"
.org $6F8B
map_control_0c6f8b:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
