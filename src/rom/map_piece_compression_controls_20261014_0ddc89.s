.setcpu "65816"
.segment "CODE"
.org $DC89
map_control_0ddc89:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
