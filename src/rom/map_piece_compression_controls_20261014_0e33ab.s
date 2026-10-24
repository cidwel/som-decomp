.setcpu "65816"
.segment "CODE"
.org $33AB
map_control_0e33ab:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
