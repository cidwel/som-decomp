.setcpu "65816"
.segment "CODE"
.org $BFDB
map_control_0fbfdb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
