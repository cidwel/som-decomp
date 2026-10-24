.setcpu "65816"
.segment "CODE"
.org $2BD2
map_control_0c2bd2:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
