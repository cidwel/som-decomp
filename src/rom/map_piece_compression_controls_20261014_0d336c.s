.setcpu "65816"
.segment "CODE"
.org $336C
map_control_0d336c:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
