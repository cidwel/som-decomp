.setcpu "65816"
.segment "CODE"
.org $C1F5
map_control_0ec1f5:
    .byte $E8 ; backreference distance high bits
    .byte $9C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
