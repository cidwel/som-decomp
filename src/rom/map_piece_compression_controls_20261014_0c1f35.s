.setcpu "65816"
.segment "CODE"
.org $1F35
map_control_0c1f35:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
