.setcpu "65816"
.segment "CODE"
.org $D42B
map_control_0fd42b:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
