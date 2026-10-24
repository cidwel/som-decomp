.setcpu "65816"
.segment "CODE"
.org $5FF3
map_control_0e5ff3:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
