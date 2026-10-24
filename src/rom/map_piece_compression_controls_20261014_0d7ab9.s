.setcpu "65816"
.segment "CODE"
.org $7AB9
map_control_0d7ab9:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
