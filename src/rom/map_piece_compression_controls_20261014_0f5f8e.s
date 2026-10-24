.setcpu "65816"
.segment "CODE"
.org $5F8E
map_control_0f5f8e:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
