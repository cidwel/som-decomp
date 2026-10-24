.setcpu "65816"
.segment "CODE"
.org $83A2
map_control_0d83a2:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
