.setcpu "65816"
.segment "CODE"
.org $77E1
map_control_0c77e1:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
