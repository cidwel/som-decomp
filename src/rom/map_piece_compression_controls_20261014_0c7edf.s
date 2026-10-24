.setcpu "65816"
.segment "CODE"
.org $7EDF
map_control_0c7edf:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
