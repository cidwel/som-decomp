.setcpu "65816"
.segment "CODE"
.org $D018
map_control_0fd018:
    .byte $E1 ; previous-row copy count
