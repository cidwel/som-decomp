.setcpu "65816"
.segment "CODE"
.org $DBDA
map_control_0ddbda:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
