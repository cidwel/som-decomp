.setcpu "65816"
.segment "CODE"
.org $DDBA
map_control_0eddba:
    .byte $EA ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
