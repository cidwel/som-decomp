.setcpu "65816"
.segment "CODE"
.org $D572
map_control_0fd572:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
