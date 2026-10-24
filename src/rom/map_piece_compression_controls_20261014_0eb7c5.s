.setcpu "65816"
.segment "CODE"
.org $B7C5
map_control_0eb7c5:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
