.setcpu "65816"
.segment "CODE"
.org $E778
map_control_0ee778:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
