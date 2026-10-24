.setcpu "65816"
.segment "CODE"
.org $23AE
map_control_0d23ae:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
