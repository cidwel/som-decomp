.setcpu "65816"
.segment "CODE"
.org $3DC5
map_control_0f3dc5:
    .byte $F2 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
