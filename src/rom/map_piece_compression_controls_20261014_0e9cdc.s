.setcpu "65816"
.segment "CODE"
.org $9CDC
map_control_0e9cdc:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
