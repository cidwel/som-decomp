.setcpu "65816"
.segment "CODE"
.org $9026
map_control_0c9026:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
