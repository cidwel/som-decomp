.setcpu "65816"
.segment "CODE"
.org $AEAF
map_control_0faeaf:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
