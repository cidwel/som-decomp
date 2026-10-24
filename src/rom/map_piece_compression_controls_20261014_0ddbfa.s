.setcpu "65816"
.segment "CODE"
.org $DBFA
map_control_0ddbfa:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2F ; distance low bit/count
