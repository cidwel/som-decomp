.setcpu "65816"
.segment "CODE"
.org $506B
map_control_0f506b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
