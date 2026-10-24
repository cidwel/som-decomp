.setcpu "65816"
.segment "CODE"
.org $90DB
map_control_0e90db:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
