; Typed eight-way acceleration vectors; docs/boss-native-target-steering.md.
.setcpu "65816"
.segment "CODE"
.org $E2F3
native_target_steering_acceleration_vectors:
    .word $0001, $0000, $0001, $0001, $0000, $0001, $FFFF, $0001
    .word $FFFF, $0000, $FFFF, $FFFF, $0000, $FFFF, $0001, $FFFF
