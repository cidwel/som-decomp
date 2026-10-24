.setcpu "65816"
.segment "CODE"
.org $470C
map_control_0d470c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
