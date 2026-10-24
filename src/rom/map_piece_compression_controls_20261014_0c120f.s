.setcpu "65816"
.segment "CODE"
.org $120F
map_control_0c120f:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
