.setcpu "65816"
.segment "CODE"
.org $34AE
map_control_0d34ae:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
