.setcpu "65816"
.segment "CODE"
.org $6719
map_control_0f6719:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
