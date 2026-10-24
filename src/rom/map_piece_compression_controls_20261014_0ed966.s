.setcpu "65816"
.segment "CODE"
.org $D966
map_control_0ed966:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
