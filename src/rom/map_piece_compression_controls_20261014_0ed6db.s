.setcpu "65816"
.segment "CODE"
.org $D6DB
map_control_0ed6db:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
