.setcpu "65816"
.segment "CODE"
.org $EACD
map_control_0eeacd:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
