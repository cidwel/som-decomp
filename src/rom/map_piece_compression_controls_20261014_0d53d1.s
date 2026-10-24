.setcpu "65816"
.segment "CODE"
.org $53D1
map_control_0d53d1:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
