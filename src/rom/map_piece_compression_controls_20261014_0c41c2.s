.setcpu "65816"
.segment "CODE"
.org $41C2
map_control_0c41c2:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $71 ; row-distance/count
