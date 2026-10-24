.setcpu "65816"
.segment "CODE"
.org $5325
map_control_0d5325:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
