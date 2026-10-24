.setcpu "65816"
.segment "CODE"
.org $99EF
map_control_0f99ef:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
