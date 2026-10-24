.setcpu "65816"
.segment "CODE"
.org $6762
map_control_0f6762:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
