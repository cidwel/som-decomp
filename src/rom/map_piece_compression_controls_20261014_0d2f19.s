.setcpu "65816"
.segment "CODE"
.org $2F19
map_control_0d2f19:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
