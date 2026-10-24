.setcpu "65816"
.segment "CODE"
.org $D83C
map_control_0fd83c:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
